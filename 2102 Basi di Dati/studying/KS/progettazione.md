Gentilmente offerto da [Kevin Speranza](https://github.com/kespers).
# Progettazione
## gerarchie entità
dette anche ISA (x is a y)
- "t" totale: ogni istanza del padre deve appartenere ad una delle figlie
- "nt" non totale: ogni istanza del padre può non appartenere
- "e" esclusiva: ogni istanza del padre può appartenere ad una solo delle figlie
- "ne" non esclusiva: ogni istanza del padre può appartenere a più istanze

## Esercizi
### ridondanza

>[!attention] assioma
>- S = operazione di scrittura
>- L = operazione di lettura
>- costo scrittura: 1 scrittura  = 2 letture (legge e scrive)

```
Dipartimento(id, nome, direttore, numero_dipendenti, citta) 
Dipendente(id, ruolo, dipartimento) 
SalarioMensileDipendente(id, salario, data) 
AnagraficaDipendente(id, cf, nome, cognome, data_nascita)
```
conviene mantenere "numero_dipendenti" in Dipartimento?

si supponga:
- 10 dipartimenti
- 5000 dipendenti

operazioni:
1. Inserimento di un dipendente in un dipartimento. Frequenza 10 al giorno; 
2. Calcolo del numero di dipendenti di un dipartimento. Frequenza 1 al giorno


- con ridondanza
O1:
1 lettura dipartimento
1 scrittura dipendente
1 scrittura dipartimento

quindi avremo:
$$
2S+1L=5L
$$

$$
O_{1\_\text{ridondanza}}=10 \cdot 5L=50L
$$

O2:
1 lettura in dipartimento
$$
O_{2\_\text{ridondanza}}=1L 
$$

in conclusione con la ridondanza avremo un costo:
$$
O_{\text{ridondanza}}=51L
$$

- senza ridondanza
O1:
1 scrittura in dipendente

$$
O_{1\_\text{No Ridondanza}}=10 \cdot 1S=10 \cdot 2L =20L
 
$$

O2:
assumendo ci siano 500 persone in ogni dipartimento, occore fare 500 letture di dipendenti
$$
O_{2\_\text{No Ridondanza}}=500L

$$

$$
O_{\text{No Ridondanza}}=520L
$$

non conviene eliminare la ridondanza

