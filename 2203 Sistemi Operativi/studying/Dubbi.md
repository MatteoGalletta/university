---
type: university
date: 2024-05-01
subjectId: 2203
year: 2
semester: 2
---
#university #studying #subject-2203
### 2024-05-01
> [!summary] Sistemi Operativi

- Perché esiste un k-stack per processo? Non basterebbe un k-stack per CPU?

- Come funzionare veramente la pipe? è a livello kernel? è un programma?
- Cos'è la shell veramente?
- In caso di pagine condivise, se un processo modifica una pagina condivisa (nella cache di livello 1 (pre-MMU)) con un'altro processo, la cache non si aggiorna (in quanto gli indirizzi virtuali non sono univoci).
- In caso di pagine condivise, la tabella dei frame, come fa a puntare a conservare il PID del processo di riferimento, se questi sono più di uno?
- Zero-fill-on-demand: com'è possibile che il malloc non crei spazio "pulito"?
- il bit di scrittura, se 0, in caso di scrittura viene sempre fatto COW?

VEDI PARGAFO PRIMA COW
per curiosità:
- vedere elenco di tutte le syscall
- vedere elenco di tutti i codici operativi di x86 o arm
