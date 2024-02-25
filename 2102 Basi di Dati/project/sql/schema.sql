
CREATE DATABASE CentroAdozione;

USE CentroAdozione;

CREATE TABLE Specie (
    Id INT AUTO_INCREMENT PRIMARY KEY,
    Nome VARCHAR(255) NOT NULL
);

CREATE TABLE Razze (
    Id INT AUTO_INCREMENT PRIMARY KEY,
    Id_Specie INT NOT NULL,
    Nome VARCHAR(255) NOT NULL,
    Descrizione TEXT NOT NULL,
    FOREIGN KEY (Id_Specie) REFERENCES Specie(Id)
);

CREATE TABLE Animali (
    Id INT AUTO_INCREMENT PRIMARY KEY,
    Nome VARCHAR(255) NOT NULL,
    Descrizione TEXT NOT NULL,
    DataDiNascita DATE,
    Maschio BOOLEAN,
    Taglia VARCHAR(50) NOT NULL,
    Colore VARCHAR(50) NOT NULL,
    Id_Razza INT NOT NULL,
    FOREIGN KEY (Id_Razza) REFERENCES Razze(Id),
    
    CHECK Taglia IN ('piccola', 'media', 'grande')
);

CREATE TABLE ImmaginiAnimali (
    Id INT AUTO_INCREMENT PRIMARY KEY,
    NomeFile VARCHAR(255) NOT NULL,
    Id_Animale INT NOT NULL,
    FOREIGN KEY (Id_Animale) REFERENCES Animali(Id)
);

CREATE TABLE Utenti (
    Id INT AUTO_INCREMENT PRIMARY KEY,
    Nome VARCHAR(100) NOT NULL,
    Cognome VARCHAR(100) NOT NULL,
    CodiceFiscale VARCHAR(16) NOT NULL,
    DataDiNascita DATE NOT NULL
);

CREATE TABLE Adozioni (
    Id INT AUTO_INCREMENT PRIMARY KEY,
    Id_Utente INT NOT NULL,
    Id_Animale INT NOT NULL,
    Data DATE NOT NULL,
    FOREIGN KEY (Id_Utente) REFERENCES Utenti(Id),
    FOREIGN KEY (Id_Animale) REFERENCES Animali(Id)
);

CREATE TABLE Donazioni (
    Id INT AUTO_INCREMENT PRIMARY KEY,
    Id_Utente INT NOT NULL,
    Importo DECIMAL(10, 2) NOT NULL,
    Data DATE NOT NULL,
    FOREIGN KEY (Id_Utente) REFERENCES Utenti(Id)
);

CREATE TABLE Ruoli (
    Id INT AUTO_INCREMENT PRIMARY KEY,
    Nome VARCHAR(100) NOT NULL
);

CREATE TABLE Personale (
    Id INT AUTO_INCREMENT PRIMARY KEY,
    DataAssunzione DATE,
    DataLicenziamento DATE,
    Esterno BOOLEAN NOT NULL,
    StipendioMensile DECIMAL(10, 2) NOT NULL DEFAULT 0,
    Id_Utente INT NOT NULL,
    Id_Ruolo INT NOT NULL,
    FOREIGN KEY (Id_Utenti) REFERENCES Utenti(Id),
    FOREIGN KEY (Id_Ruolo) REFERENCES Ruoli(Id)
);

CREATE TABLE OrariDiLavoro (
    Id INT AUTO_INCREMENT PRIMARY KEY,
    Id_Personale INT NOT NULL,
    WeekDay TINYINT NOT NULL,
    HourFrom TIME NOT NULL,
    HourTo TIME NOT NULL,
    FOREIGN KEY (Id_Personale) REFERENCES Personale(Id),
    CHECK (HourFrom < HourTo)
);

CREATE TABLE StruttureOspitanti (
    Id INT AUTO_INCREMENT PRIMARY KEY,
    Nome VARCHAR(255) NOT NULL,
    Lunghezza FLOAT NOT NULL,
    Larghezza FLOAT NOT NULL,
    Altezza FLOAT NOT NULL,
    Tipo VARCHAR(20) NOT NULL,
    CHECK Tipo IN ('gabbia', 'recinto', 'stanza')
);

CREATE TABLE CollocamentoAnimali (
    Id INT AUTO_INCREMENT PRIMARY KEY,
    DataDiArrivo DATE NOT NULL,
    DataDiAdozione DATE NOT NULL,
    Id_Animale INT NOT NULL,
    Id_Struttura INT NOT NULL,
    FOREIGN KEY (Id_Animale) REFERENCES Animali(Id),
    FOREIGN KEY (Id_Struttura) REFERENCES StruttureOspitanti(Id)
);

CREATE TABLE Prestazioni (
    Id INT AUTO_INCREMENT PRIMARY KEY,
    Data DATE NOT NULL,
    Descrizione TEXT NOT NULL,
    Importo DECIMAL(10, 2) NOT NULL DEFAULT 0,
    Note TEXT NOT NULL,
    PrestazioneAnimale BOOLEAN,
    Id_Personale INT NOT NULL,
    FOREIGN KEY (Id_Personale) REFERENCES Personale(Id)
);

CREATE TABLE AnimaliPrestazione (
    Id INT AUTO_INCREMENT PRIMARY KEY,
    Id_Prestazione INT NOT NULL,
    Id_Animale INT NOT NULL,
    FOREIGN KEY (Id_Prestazione) REFERENCES Prestazioni(Id),
    FOREIGN KEY (Id_Animale) REFERENCES Animali(Id)
);

CREATE TABLE StrutturePrestazione (
    Id INT AUTO_INCREMENT PRIMARY KEY,
    Id_Prestazione INT NOT NULL,
    Id_Struttura INT NOT NULL,
    FOREIGN KEY (Id_Prestazione) REFERENCES Prestazioni(Id),
    FOREIGN KEY (Id_Struttura) REFERENCES StruttureOspitanti(Id)
);

CREATE TABLE Prodotti (
    Id INT AUTO_INCREMENT PRIMARY KEY,
    Nome VARCHAR(255) NOT NULL,
    Descrizione TEXT NOT NULL,
    QuantitaDisponibile INT NOT NULL
);

CREATE TABLE Fornitori (
    Id INT AUTO_INCREMENT PRIMARY KEY,
    Nome VARCHAR(255) NOT NULL,
    Indirizzo VARCHAR(255),
    Email VARCHAR(255),
    NumeroTelefono VARCHAR(20)
);

CREATE TABLE Forniture (
    Id INT AUTO_INCREMENT PRIMARY KEY,
    Importo DECIMAL(10, 2) NOT NULL,
    Data DATE NOT NULL,
    Id_Prodotto INT NOT NULL,
    Id_Fornitore INT NOT NULL,
    Quantita INT NOT NULL,
    FOREIGN KEY (Id_Prodotto) REFERENCES Prodotti(Id),
    FOREIGN KEY (Id_Fornitore) REFERENCES Fornitori(Id)
    CHECK Quantita > 0
);

CREATE TABLE UtilizzoProdotto (
    Id INT AUTO_INCREMENT PRIMARY KEY,
    Quantita INT NOT NULL,
    Id_Prestazione INT NOT NULL,
    Id_Prodotto INT NOT NULL,
    FOREIGN KEY (Id_Prestazione) REFERENCES Prestazione(Id),
    FOREIGN KEY (Id_Prodotto) REFERENCES Prodotto(Id)
);

CREATE TABLE StoricoSpese (
    Id INT AUTO_INCREMENT PRIMARY KEY,
    Importo DECIMAL(10, 2) NOT NULL,
    Descrizione TEXT NOT NULL
    Tipo ENUM('prestazione', 'stipendio', 'fornitura', 'altro') NOT NULL,
    Id_Prestazione INT,
    Id_Personale INT,
    Id_Fornitura INT,
    FOREIGN KEY (Id_Prestazione) REFERENCES Prestazione(Id),
    FOREIGN KEY (Id_Persona) REFERENCES Persona(Id),
    FOREIGN KEY (Id_Fornitura) REFERENCES Fornitura(Id)
);

