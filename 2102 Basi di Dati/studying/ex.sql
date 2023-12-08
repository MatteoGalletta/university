SELECT p1.id, p3.id
FROM Persona p1, Persona p2, Persona p3
WHERE p1.id != p3.id
AND EXISTS (
	SELECT *
	FROM Evento e
	WHERE EXISTS (
		SELECT *
		FROM Partecipante p
		WHERE p.idevento = e.id AND p.idpersona = p1.id
	) AND EXISTS (
		SELECT *
		FROM Partecipante p
		WHERE p.idevento = e.id AND p.idpersona = p2.id
	)
) AND EXISTS (
	SELECT *
	FROM Evento e
	WHERE EXISTS (
		SELECT *
		FROM Partecipante p
		WHERE p.idevento = e.id AND p.idpersona = p2.id
	) AND EXISTS (
		SELECT *
		FROM Partecipante p
		WHERE p.idevento = e.id AND p.idpersona = p3.id
	)
) AND NOT EXISTS (
	SELECT *
	FROM Evento e
	WHERE EXISTS (
		SELECT *
		FROM Partecipante p
		WHERE p.idevento = e.id AND p.idpersona = p1.id
	) AND EXISTS (
		SELECT *
		FROM Partecipante p
		WHERE p.idevento = e.id AND p.idpersona = p3.id
	)
)
	

