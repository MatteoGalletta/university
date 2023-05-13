---
type: university
date: 2022-11-27
subjectId: 1102
year: 1
semester: 1
---
#university #studying #subject-1102
### 2022-11-27
> [!summary] Architettura degli Elaboratori

**Il Frame Pointer (FP)** punta all'*area di attivazione* (*stack frame*/*activation record*). Punta ad una parola che contiene l'FP del chiamante e, tramite la tecnica di indice e spiazzamento, è possibile accedere ai parametri della funzione (arguments) con indice negativo e alle variabili locali con indice positivo. L'FP è di fatto **inutile**, si potrebbe accedere alle informazioni utilizzando l'SP (Stack Pointer), in questo modo però si dovrebbe tener conto dello spostamento di SP tenendo traccia dei vari incrementi/decrementi (spcialmente se il numero di variabili locali è dinamico).

L'FP serve quindi allo sviluppatore per semplificazione (non deve gestire il tener traccia dell'SP) e al debugger che non conosce la struttura dell'area di attivazione (ovvero il confine tra variabili locali e parametri).

Supposizione verificata:
- https://softwareengineering.stackexchange.com/questions/303446/why-is-a-frame-pointer-set-as-an-offset-from-the-stack-Pointer
- https://www.quora.com/Why-is-it-more-convenient-to-use-the-frame-pointer-rather-than-stack-pointer-for-stack-frame-addressing
