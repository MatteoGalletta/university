--- Op. 1: Elencare gli animali con colore, taglia ed età specifici ---
-- (in questo caso un cane, labrador, marrone, piccolo o medio, con meno di 5 anni)
SELECT a.*
FROM Animali a
JOIN Razze r ON r.Id = a.Id_Razza
JOIN Specie s ON s.Id = r.Id_Specie
WHERE
	LOWER(s.Nome) LIKE '%cane%' AND
	LOWER(r.Nome) LIKE '%labrador%' AND
	LOWER(a.Colore) LIKE '%marrone%' AND
	a.Taglia IN ('piccola', 'media') AND
	(TIMESTAMPDIFF(YEAR, CURDATE(), a.DataDiNascita) <= 5 OR a.DataDiNascita IS NULL);

--- Op. 2 Ottenere gli animali arrivati (e in attesa di essere adottati) da più di un determinato numero di giorni ---
-- (in questo caso gli animali arrivati da più di 3 mesi)
SELECT a.*
FROM Animali a
WHERE EXISTS (
	SELECT *
	FROM CollocamentoAnimali ca
	WHERE
		ca.Id_Animale = a.Id AND
		DATEDIFF(CURDATE(), ca.DataDiArrivo) >= 6*30 AND
		ca.DataDiAdozione IS NULL
);

--- Op. 3 Individuare il personale attualmente disponibile ---
SELECT p.*
FROM Personale p
JOIN OrariDiLavoro odl ON odl.Id_Personale = p.Id
WHERE odl.WeekDay = WEEKDAY(CURDATE()) AND CURTIME() BETWEEN odl.HourFrom AND odl.HourTo;

--- Op. 4 Individuare il numero di animali disponibili di una determinata razza ---
-- (in questo caso i bulldog disponibili)
SELECT COUNT(*)
FROM Animali a
JOIN Razze r ON a.Id = a.Id_Razza
WHERE LOWER(r.Nome) LIKE '%bulldog%';

--- Op. 5 Individuare il ricavo medio mensile derivato da donazioni ---
SELECT AVG(mesi.Importo) AS 'Ricavo medio mensile da donazioni'
FROM (
	SELECT SUM(d.Importo) AS Importo
	FROM Donazioni d
	GROUP BY MONTH(d.Data)
) AS mesi;

--- Op. 6 Individuare il numero di adozioni medie mensili ---
SELECT AVG(mesi.Numero) AS 'Numero adozioni medie mensili'
FROM (
	SELECT COUNT(*) AS Numero
	FROM Donazioni d
	GROUP BY MONTH(d.Data)
) AS mesi;

--- Op. 7 Inserimento di un animale ---
INSERT INTO Animali (Nome, Descrizione, Maschio, Taglia, Colore, Id_Razza) VALUES
('Tino', '', 1, 'piccola', 'nero', 1);

--- Op. 8 Effettuare il pagamento degli stipendi ai dipendenti ---
CALL PagaStipendiInStoricoSpese();

