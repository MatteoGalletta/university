
USE CentroAdozioneAnimali;

DELIMITER $$

CREATE TRIGGER IF NOT EXISTS CheckOrariDiLavoro
BEFORE INSERT ON OrariDiLavoro
FOR EACH ROW
BEGIN
	IF EXISTS (
		SELECT *
		FROM OrariDiLavoro o
		WHERE
			new.Id_Personale = o.Id_Personale AND
			new.WeekDay = o.WeekDay AND
			((new.HourFrom BETWEEN o.HourFrom AND o.HourTo) OR
			(new.HourTo BETWEEN o.HourFrom AND o.HourTo))
	) THEN
		SIGNAL SQLSTATE '45000' SET MESSAGE_TEXT = 'L''orario specificato si sovrappone con altri orari.';
	END IF;
END$$

CREATE TRIGGER IF NOT EXISTS InsertPrestazioniInStoricoSpese
AFTER INSERT ON Prestazioni
FOR EACH ROW
BEGIN
	INSERT INTO StoricoSpese (Data, Importo, Descrizione, Tipo, Id_Prestazione)
	VALUES (new.Data, new.Importo, CONCAT('Prestazione ', new.Id), 'prestazione', new.Id);
END$$

CREATE TRIGGER IF NOT EXISTS UpdatePrestazioniInStoricoSpese
AFTER UPDATE ON Prestazioni
FOR EACH ROW
BEGIN
	UPDATE StoricoSpese
	SET Importo = new.Importo, Id_Prestazione = new.Id, Descrizione = CONCAT('Prestazione ', new.Id)
	WHERE Id_Prestazione = old.Id;
END$$
DELIMITER ;

