
CREATE PROCEDURE PagaStipendiInStoricoSpese()
BEGIN

	DECLARE id INT;
	DECLARE stipendio INT;
	DECLARE done INT DEFAULT 0;

	DECLARE DipendentiDaPagare CURSOR FOR
		SELECT p.Id, p.StipendioMensile
		FROM Personale p
		WHERE p.Esterno = FALSE AND p.StipendioMensile > 0 AND p.DataLicenziamento IS NULL;

	DECLARE CONTINUE HANDLER FOR NOT FOUND SET done = 1;
	
	OPEN DipendentiDaPagare;
	
	
lbl:
	LOOP
		IF done = 1 THEN
			LEAVE lbl;
		END IF;
		
		FETCH DipendentiDaPagare INTO id, stipendio;
		
		INSERT INTO StoricoSpese(Data, Importo, Descrizione, Id_Personale)
		VALUES (CURDATE(), stipendio, CONCAT('Stipendio per il dipendente ', id, ' del mese di ', MONTHNAME(CURDATE())), id);
	
    END LOOP;
END

