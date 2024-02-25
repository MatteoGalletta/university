
CREATE TRIGGER "CheckOrariDiLavoro"
BEFORE INSERT ON "OrariDiLavoro"
FOR EACH ROW
BEGIN
	IF EXISTS (
		SELECT *
		FROM OrariDiLavoro o
		WHERE new.Id_Utente = o.Id_Utente
			((new.HourFrom BETWEEN o.HourFrom AND o.HourTo) OR
			(new.HourTo BETWEEN o.HourFrom AND o.HourTo))
	) THEN
		SIGNAL SQLSTATE '000001' ('L\'orario specificato si sovrappone con altri orari.')
	END IF
END

CREATE TRIGGER "InsertPrestazioniInStoricoSpese"
AFTER INSERT ON "Prestazioni"
FOR EACH ROW
BEGIN
	INSERT INTO "StoricoSpese" ("Data", "Importo", "Descrizione")
	VALUES (new.Data, new.Importo, CONCAT('Prestazione ', new.Id))
END

CREATE TRIGGER "UpdatePrestazioniInStoricoSpese"
AFTER UPDATE ON "Prestazioni"
FOR EACH ROW
BEGIN
	UPDATE "StoricoSpese" SET "Importo" = new.Importo
	WHERE "Descrizione" = CONCAT('Prestazione ', new.Id))
END

CREATE PROCEDURE "PagaStipendiInStoricoSpese"()
BEGIN
	DECLARE DipendentiDaPagare CURSOR FOR
		SELECT p.Id, p.StipendioMensile
		FROM Personale p
		WHERE p.Esterno = FALSE AND p.StipendioMensile > 0 AND p.DataLicenziamento IS NULL
	
	DECLARE done INT DEFAULT FALSE;
	DECLARE CONTINUE HANDLER FOR NOT FOUND SET done = TRUE;
	
	OPEN DipendentiDaPagare;
	
lbl:
	LOOP
		IF done = TRUE THEN
			LEAVE lbl;
		END IF;
		
		FETCH DipendentiDaPagare INTO id, stipendio;
		
		INSERT INTO "StoricoSpese" ("Data", "Importo", "Descrizione")
		VALUES (CURDATE(), stipendio, CONCAT('Stipendio per il dipendente ', new.Id, ' del mese di ', MONTHNAME(CURDATE())))
	
    END LOOP;
END


