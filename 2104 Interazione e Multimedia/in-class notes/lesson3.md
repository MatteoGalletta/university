---
annotation-target: ../lessons/Lez 03 - Operazioni sulle matrici.pdf
---


>%%
>```annotation-json
>{"created":"2023-10-19T09:14:25.890Z","text":"Devo trovare cosa mettere nelle coordinate (2,2).\nPrendo i quattro punti attorno, utilizzo l'equazione e le metto in un sistema. Trovo a, b, c e d.\nEsempio: nelle coordinate (1,1) c'è un punto con valore 5. Ottengo la seguente equazione:\n$v(1,1)=a+b+c+d=5$\n\nTrovo a, b, c e d e li sostituisco nell'equazione originale. Ho calcolato il valore\n\n1. I pixel in colonne e righe pari si calcolano sulla base dei 4 pixel diagonali.\n2. I pixel in colonne o righe dispari si calcolano sulla base dei 4 pixel orizzontali/verticali.\n\nCi saranno ai bordi dei punti in cui non ho a disposizione i 4 pixel vicini. In questi punti si può fare la media tra i valori noti vicini disponibili o, nel caso dell'ultima riga e colonna, copiare la penultima.","updated":"2023-10-19T09:14:25.890Z","document":{"title":"Interazione & Multimedia","link":[{"href":"urn:x-pdf:f25afcbd08a92c41bfda37fde81be2bf"},{"href":"vault:/100 university/2104 Interazione e Multimedia/lessons/Lez 03 - Operazioni sulle matrici.pdf"}],"documentFingerprint":"f25afcbd08a92c41bfda37fde81be2bf"},"uri":"vault:/100 university/2104 Interazione e Multimedia/lessons/Lez 03 - Operazioni sulle matrici.pdf","target":[{"source":"vault:/100 university/2104 Interazione e Multimedia/lessons/Lez 03 - Operazioni sulle matrici.pdf","selector":[{"type":"TextPositionSelector","start":5013,"end":5021},{"type":"TextQuoteSelector","exact":"Bilinear","prefix":"ilinear Interazione & Multimedia","suffix":" Nell’interpolazione bilineare "}]}]}
>```
>%%
>*%%PREFIX%%ilinear Interazione & Multimedia%%HIGHLIGHT%% ==Bilinear== %%POSTFIX%% Nell’interpolazione bilineare*
>%%LINK%%[[#^2m68xuy5gxb|show annotation]]
>%%COMMENT%%
>Devo trovare cosa mettere nelle coordinate (2,2).
>Prendo i quattro punti attorno, utilizzo l'equazione e le metto in un sistema. Trovo a, b, c e d.
>Esempio: nelle coordinate (1,1) c'è un punto con valore 5. Ottengo la seguente equazione:
>$v(1,1)=a+b+c+d=5$
>
>Trovo a, b, c e d e li sostituisco nell'equazione originale. Ho calcolato il valore
>
>1. I pixel in colonne e righe pari si calcolano sulla base dei 4 pixel diagonali.
>2. I pixel in colonne o righe dispari si calcolano sulla base dei 4 pixel orizzontali/verticali.
>
>Ci saranno ai bordi dei punti in cui non ho a disposizione i 4 pixel vicini. In questi punti si può fare la media tra i valori noti vicini disponibili o, nel caso dell'ultima riga e colonna, copiare la penultima.
>%%TAGS%%
>
^2m68xuy5gxb
