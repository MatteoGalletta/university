---
type: university
date: 2023-10-31
subjectId: 2102
year: 2
semester: 1
---
#university #studying #subject-2102
### Basi di Basi di Dati
> [!summary] Basi di Dati

## Algebra Relazionale

Simboli:
- $\pi$ Proiezione (filtra le colonne)
- $\delta$ Ridenominazione (rinomina le colonne)
- $\sigma$ Selezione (filtra le righe)
- $\times$ Prodotto cartesiano
- $\bowtie$ Natural Join (unisce due tabelle confrontando le colonne con lo stesso nome)
- $\bowtie_\text{a>b}$ Theta Join (unisce due tabelle confrontando le colonne specificate)
- $\bowtie_\text{a=b}$ Equi Join (unisce due tabelle confrontando le colonne specificate esclusivamente con l'operatore $=$)
- $\cup$ Unione
- $\cap$ Intersezione
- $-$ Differenza
- $\bowtie^{\longleftrightarrow}$ Full Natural Outer-Join (unisce due tabelle confrontando la colonne uguali e prendendo anche le righe nulle di entrambe le tabelle) \[Al posto della freccia puoi scrivere FULL\]
- $\bowtie^{\longleftarrow}$ Full Natural Left-Join (unisce due tabelle confrontando la colonne uguali e prendendo anche le righe nulle della tabella a destra). \[Al posto della freccia puoi scrivere LEFT\]
- $\bowtie^{\longrightarrow}$ Full Natural Right-Join (unisce due tabelle confrontando la colonne uguali e prendendo anche le righe nulle della tabella a sinistra) \[Al posto della freccia puoi scrivere RIGHT\]
- $\ltimes$ Semi-Join Left (unisce le due tabelle con un EquiJoin e fa la proiezione dei campi della tabella a sinistra)
- $\rtimes$ Semi-Join Right (unisce le due tabelle con un EquiJoin e fa la proiezione dei campi della tabella a destra)
- $\cup^{\longleftrightarrow}$ Unione Esterna (fa l'unione anche se ci sono colonne diverse. Le colonne diverse vengono messe $=null$)
- $\div$ Divisione (prende le righe della tabella a sinistra che hanno corrispondenza con tutte le righe della tabella a destra)

> [!faq] Esempio
```
Prodotto(costruttore, id_modello, tipo)
PC(id_modello, velocità, ram, hd_size, risoluzione, prezzo)
Laptop(id_modello, velocità, ram, hd_size, risoluzione, prezzo)
Stampante(id_modello, colore, tipo, prezzo)  

Trovare gli hd_size che sono presenti in due o più PC:
R1 = RIDENOMINAZIONE[P1_*](PC) EQUIJOIN[P1_hd_size = P2_hd_size, P1_id_modello > P2_id_modello] RIDENOMINAZIONE[P2_*](PC)
R2 = PROIEZIONE[hd_size](R1)

Trovare i costruttori di computer (PC o Laptop) con la velocità più alta;

R1 = proiezione[id_modello, velocita](PC) UNIONE proiezione[id_modello, velocita](Laptop)
R2 = R1  
R3 = proiezione[R1.id_modello](selezione[R1.velocita < R2.velocita](R1 X R2))
R4 = proiezione[id_modello](Prodotto) - R3
R5 = proiezione[costruttore](Prodotto NATURAL JOIN R4)

SQL:
SELECT costruttore
FROM Prodotto
WHERE velocità IN (
	SELECT MAX(IF(PC.velocità > Laptop.velocità; PC.velocità; Laptop.velocità))
	FROM (SELECT * FROM PC), (SELECT * FROM Laptop)
)
```

## MySQL

- `UNION [ALL]`/`INTERSECT [ALL]`/`EXCEPT [ALL]` (l'`ALL` indica di mantenere i duplicati)
- La divisione si implementa con un doppio `NOT EXISTS`

### Main Types
- INT, BIGINT, FLOAT, DOUBLE, BIT, DATE, DATETIME, TIME, TIMESTAMP, CHAR, VARCHAR

### Main Functions
- CURRENT_DATE, CURRENT_TIME, CURRENT_TIMESTAMP, 

### Account and Privileges
#### Creazione e assegnazione
```sql
CREATE USER 'name'@'host' IDENTIFIED BY 'password';
```
Per assegnare permessi a un utente:
```sql
GRANT permesso1, permesso2, ... permesson
ON * | 'db'.* | 'db'.'table'
TO 'username1'@'host', ..., 'usernamen'@'host';
```
Permessi: `ALL, USAGE, SELECT, INSERT, UPDATE, DELETE, CREATE, ALTER, INDEX, DROP, CREATE VIEW, TRIGGER`.

#### Eliminazione e rimozione
```sql
DROP USER 'name'@'host';
```
Per assegnare permessi a un utente:
```sql
REVOKE permesso1, permesso2, ... permesson
ON * | 'db'.* | 'db'.'table'
FROM 'username1'@'host', ..., 'usernamen'@'host';
```
Permessi: `ALL, USAGE, SELECT, INSERT, UPDATE, DELETE, CREATE, ALTER, INDEX, DROP, CREATE VIEW, TRIGGER`.

### Database
```sql
CREATE DATABASE [IF NOT EXISTS] nome;
...
USE nome;
...
DROP DATABASE [IF EXISTS] nome;
```

### Tables
```sql
CREATE TABLE [IF NOT EXISTS] nome (
	campo1 TIPO [CONSTRAINTS],
	campo2 TIPO [CONSTRAINTS],
	...
	campon TIPO [CONSTRAINTS]
)
```
dove `constraints` sono:
- `NOT NULL`
- `AUTO_INCREMENT`
- `DEFAULT [valore]`
- `PRIMARY KEY`
	- Può anche essere messo in un'altra riga: `PRIMARY KEY (colonna1, ..., colonnan)`
- `FOREIGN KEY REFERENCES nome_tabella (colonna_esterna)`
	- Può essere messo in un'altra riga: `CONSTRAINT fk_table1_table2 FOREIGN KEY (colonna) REFERENCES nome_tabella (colonna_esterna)`

```
ALTER TABLE nome
[OPERATIONS] {, [OPERATIONS]}
```
le `OPERATIONS` sono:
- `ADD COLUMN nome_colonna TIPO [CONSTRAINTS]` (stessa sintassi della `CREATE`)
- `DROP COLUMN nome_colonna`
- `RENAME COLUMN old_name TO new_name`

```sql
RENAME TABLE old_name TO new_name
```
### Trigger
```sql
CREATE TRIGGER TriggerName
{ before | after }
{ insert | delete | update [of Column] } on Table
[referencing
	{[old_table [as] OldTableAlias]
	[new_table [as] NewTableAlias] } |
	{[old [row] [as] OldTupleName]
	[new [row] [as] NewTupleName] }]
[for each { row | statement }]
[when Condition]
SQLStatements
```

esempio
```sql
create trigger FileDeletedInvoices
after delete on Invoice
referencing old_table as OldInvoiceSet
insert into DeletedInvoices
	(select *
	from OldInvoiceSet)
```

Quando si usa "for each statement" invece di "for each row" in "SQLStatements" ci potranno finire le classiche operazioni come INSERT INTO, UPDATE, DELETE, ecc.
Nel caso di "for each row", invece, si aggiunge la possibilità di utilizzare una sintassi propria.
Si usa `SET` per aggiornare i campi NEW, ad esempio:
`SET NEW.total = 5 * OLD.total`

### View
```sql
CREATE VIEW NomeView(col1, col2) AS
SELECT ...
```
`col1` e `col2` sono i nomi delle colonne ritornate. Possono essere omesse (verrebbero prese in automatico dai campi del select).

`WITH CHECK OPTION` fa controllare in fase di inserimento all'interno della view che vengano rispettate le condizioni del `WHERE`.
### Check
Si mette nella definizione della tabelle
```sql
CHECK (query_che_ritorna_un_booleano)
```

es. `CHECK ((SELECT MIN(prezzo) FROM prodotti) >= 0)`

Se serve fare un controllo **intra-relazionale** (che si spalma su più tabelle) è necessaria la seguente sintassi:
```sql
CREATE ASSERTION nome_asserzione
CHECK (query_che_ritorna_un_booleano)
```

### Procedure
```sql
CREATE PROCEDURE nome_procedura(IN p1 INT)
BEGIN
	blocco_istruzioni
END
```
`IN` è opzionale
Si richiama con `CALL nome_procedura(arg1, ..., argn)`
### Funzioni
```sql
CREATE FUNCTION nome_funzione(IN p1 INT, OUT p2 INT, INOUT p3 INT)
BEGIN
	blocco_istruzioni

	SELECT ...
END
```
L'ultima riga è quella che effettivamente consente di ritornare un valore
Si richiama con `CALL nome_funzione(arg1, ..., argn)`

### Transazioni
```sql
START TRANSACTION;
query1
query2
...
queryn
COMMIT WORK;
```

### Select Case
```sql
CASE value
	WHEN match1 THEN ...,
	WHEN match2 THEN ...,
	...
	WHEN matchn THEN ...
	[ELSE ...]
END
```

### Where LIKE
```
...
WHERE column LIKE 'pattern';
```
Pattern può contenere due simboli speciali:
- `%`: zero o più caratteri
- `_`: esattamente un carattere

### Insert, Update, Delete
##### Per inserire valori costanti
```sql
INSERT INTO mytable (field1, ..., fieldn) VALUES (value1, ..., valuen)
```
Se si inseriscono valori di tutte le colonne della tabella, i `field` possono essere omessi.

##### Per inserire valori da query
```sql
INSERT INTO mytable (field1, ..., fieldn) SELECT ...
```

##### Per aggiornare con valori costanti
```sql
UPDATE mytable SET col1 = val1, ..., colN = valN
WHERE ...
```

##### Per eliminare
```sql
DELETE FROM mytable
WHERE ...
```

### Limit, Offset
##### Per ritornare i primi n elementi di una query
```
SELECT ...
FROM ...
...
LIMIT n
```
##### Per ritornare i primi n elementi di una query saltando i primi m
```
SELECT ...
FROM ...
...
LIMIT m, n
```

### Sintassi body trigger/funzioni/procedure
#### DECLARE
##### Per le variabili
```sql
DECLARE variabile TIPO [DEFAULT valore_default]
```
Nota: le variabili globali NON vanno dichiarate.
##### Per i cursori
*vedi sotto sezione dedicata*

#### Assegnazione variabili
##### Da costante o altra variabile
```sql
SET variabile = 5;
SET variabile = var2;
SET @variabile_globale = 8;
```
Per le variabili globali è necessario mettere come prefisso al nome della variabile il simbolo `@`.
##### Da risultato di query
```sql
SELECT value INTO variabile
FROM ...
```
#### IF
```sql
IF (condizione) THEN
	body_if
END IF;
```

Sintassi completa con `else`:
```sql
IF (condizione) THEN
	body_if
ELSEIF (condizione) THEN
	body_elseif
ELSE
	body_else
END IF;
```

#### WHILE
```sql
WHILE (condizione) DO
	body_while
END WHILE;
```

#### REPEAT UNTIL
```sql
REPEAT
	body_repeatuntil
UNTIL (condizione)
END REPEAT;
```
Nota: la condizione del repeat until è invertita. Il ciclo viene ripetuto finché la condizione non diventa vera (a quel punto si esce).

#### LOOP
```sql
loop_label: LOOP
	...istruzioni...
	IF (condizione)
		LEAVE loop_label;
	END IF
	...istruzioni...
	IF (condizione)
		ITERATE loop_label;
	END IF
	...istruzioni...
END LOOP
```

#### CURSOR
```sql
DECLARE cursor_name CURSOR FOR SELECT ...

OPEN cursor_name;

DECLARE stop_iterating INT DEFAULT 0
DECLARE CONTINUE HANDLER FOR NOT FOUND SET stop_iterating = 1

...

REPEAT
	...
	FETCH cursor_name INTO var1, var2, ..., varn;
	...
UNTIL stop_iterating = 1

...

CLOSE cursor_name;
```

Qualora si utilizzasse un `TRIGGER` con clausola `BEFORE`, può essere utile restituire un errore all'utente quando l'input non è valido. Si utilizza quindi quanto segue:
```
SIGNAL SQLSTATE ‘00001’ (‘MESSAGGIO DI ERRORE’)
```
