#ifndef DATA_H
    #define DATA_H

    // int value
    struct dato{
        int value;
    };

    // come strcpm() => confronta due dati
    int confrontaDati(struct dato *d1,struct dato *d2);

    // stampa dato
    void printDato(struct dato *d);
#endif