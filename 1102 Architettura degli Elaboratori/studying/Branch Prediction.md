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

**T**: Salto Effettuato
**F**: Salto Non Effettuato

## Due stadi
**PS** (Probabilmente Salta) e **PNS** (Probabilmente Non Salta)

**Algoritmo**:
- PS:
	- **T** -> PS
	- **F** -> PNS
- PNS:
	- **T** -> PS
	- **F** -> PNS

## Quattro stadi
**PS** (Probabilmente Salta) e **PNS** (Probabilmente Non Salta)
**MPS** (Molto Probabilmente Salta) e **MPNS** (Molto Probabilmente Non Salta)

**Algoritmo**:
- PS:
	- **T** -> MPS
	- **F** -> MPNS
- PNS:
	- **T** -> MPNS
	- **F** -> MPS
- MPS:
	- **T** -> MPS
	- **F** -> PS
- MPNS:
	- **T** -> MPNS
	- **F** -> PNS
