--- Op. 1: Elencare gli animali con colore, taglia ed età specifici ---
-- (in questo caso un cane, pitbull, marrone, piccolo o medio, con meno di 5 anni)
SELECT a.*
FROM Animali a
JOIN Razze r ON r.Id = a.Id_Razza
JOIN Specie s ON s.Id = r.Id_Specie
WHERE
	LOWER(s.Nome) LIKE '%cane%' AND
	LOWER(r.Nome) LIKE '%pitbull%' AND
	LOWER(a.Colore) LIKE '%marrone%' AND
	a.Taglia IN ('piccola', 'media') AND
	(DATEDIFF(a.DataDiNascita, CURDATE()) AS 'Years' <= 5 OR a.DataDiNascita IS NULL);

--- Op. 2 Ottenere gli animali arrivati da più di un determinato numero di giorni ---
-- (in questo caso un gatto arrivato da più di 6 mesi)
SELECT a.*
FROM Animali a
WHERE EXISTS (
	SELECT *
	FROM CollocamentoAnimali ca
	WHERE
		ca.DataDiArrivo = (
			SELECT MAX(ca2.DataDiArrivo)
			FROM CollocamentoAnimali ca2
			WHERE ca.Id_Animale = a.Id
		) AND
		ca.Id_Animale = a.Id AND
		DATEDIFF(ca.DataDiArrivo, CURDATE()) AS 'Days' >= 6*30 AND
		ca.DataDiUscita IS NULL
);

--- Op. 3 Individuare il personale attualmente disponibile ---
SELECT p.*
FROM Personale p
JOIN OrarioDiLavoro odl ON odl.Id_Persona = p.Id
WHERE odl.WeekDay = WEEKDAY(CURDATE()) AND CURTIME() BETWEEN odl.HourFrom AND odl.HourTo;

--- Op. 4 Individuare il numero di animali disponibili di una determinata razza ---
-- (in questo caso i pitbull disponibili)
SELECT COUNT(*)
FROM Animali a
JOIN Razze r ON a.Id = a.Id_Razza
WHERE LOWER(r.Nome) LIKE '%pitbull%'

--- Op. 5 Individuare il ricavo medio mensile derivato da donazioni ---
SELECT AVG(c) AS 'Ricavo medio mensile da donazioni'
FROM (
	SELECT AVG(d.Importo) AS c
	FROM Donazioni d
	GROUP BY MONTH(d.Data)
);

--- Op. 6 Individuare il numero di adozioni medie mensili ---
SELECT AVG(c) AS 'Numero adozioni medie mensili'
FROM (
	SELECT COUNT(*) AS c
	FROM Donazioni d
	GROUP BY MONTH(d.Data)
);

--- Op. 7 Inserimento di un animale ---
INSERT INTO Animale (Nome, Maschio, Taglia, Colore, Id_Razza) VALUES
('Tino', 1, 'piccola', 'nero', 1);

--- Op. 8 Effettuare il pagamento degli stipendi ai dipendenti ---
CALL PagaStipendiInStoricoSpese();
