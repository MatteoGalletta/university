---
type: university
date: 2023-02-26
subjectId: 1102
year: 1
semester: 1
---
#university #studying #subject-1102
### 2023-02-26
> [!summary] Architettura degli Elaboratori

## Cache Hit
- **Lettura**:
	- Memoria Centrale non coinvolta
- **Scrittura**
	- Scrittura Immediata (Write Through):
		- nel momento della scrittura viene scritto il dato anche in RAM
	- Scrittura Differita (Write Back):
		- viene aggiornato un bit e l'aggiornamento in RAM avviene soltanto quando il blocco viene rimosso dalla cache

## Cache Miss
- **Lettura**
	- si attende che dalla RAM la parola venga caricata in cache
	- Scrittura Immediata (Write Through):
		- Si legge la parola non appena caricata
	- Scrittura Differita (Write Back):
		- Si legge la parola solo dopo l'intero caricamento del blocco
- **Scrittura**
	- Scrittura Immediata (Write Through):
		- nel momento della scrittura viene scritto il dato direttamente nella RAM
	- Scrittura Differita (Write Back):
		- viene copiato nella cache il blocco e successivamente avviene la scrittura del dato nella cache.
