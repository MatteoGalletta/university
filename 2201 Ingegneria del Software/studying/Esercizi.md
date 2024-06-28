---
type: university
date: 2024-06-22
subjectId: 2201
year: 2
semester: 2
---
#university #studying #subject-2201
### Esercizi
> [!summary] Ingegneria del Software


# L21_JavaStreamParte2.pdf

### es. 1

```
String prefix = "kek";

Stream<String> elementi = Stream.of(“author”, “auto”, “autocorrect”, “begin”, “big”, “bigger”, “biggish”)
	.filter(x -> x.substring(0, prefix.length()).equals(prefix));
```

### es. 2

```
String str = Stream.of(“to”, “speak”, “the”, “truth”, “and”, “pay”,
“your”, “debts”)
	.map(x -> x.substring(0, 1))
	.reduce("", (accumulator, prefixChar) -> accumulator + prefixChar);
```


### es. 3

```
Stream<int> x = Stream.of(new ArrayList<int>(Array.asList(2, 3, 4)), ...)
	.filter(x -> x.size() == 3
			  && x.get(0) + x.get(1) > x.get(2)
			  && x.get(1) + x.get(2) > x.get(0)
			  && x.get(2) + x.get(0) > x.get(1))
	.map(x -> x.stream().sum());
```

### es. 4

```
List<int> listaNumeriInteri = new ArrayList<int>(Array.asList(2, 3, 5, 7, 8));

List<int[]> l = IntStream.rangeClosed(0, listaNumeriInteri.length() - 3)
	.mapToObj(x -> new int[] {listaNumeriInteri.get(x),
						 listaNumeriInteri.get(x + 1),
						 listaNumeriInteri.get(x + 2)})
	.filter(x -> x.size() == 3 // todo: occhio che non è un arraylist
			  && x.get(0) + x.get(1) > x.get(2)
			  && x.get(1) + x.get(2) > x.get(0)
			  && x.get(2) + x.get(0) > x.get(1))
	.collect(Collectors.toList())
```

### es. 5

```
List<int> myList = new ArrayList(2, 4, 5);

bool isOrdered = IntStream.rangeClosed(0, myList.length())
	.filter(x -> myList.get(x) > myList.get(x + 1))
	.findAny()
	.isEmpty()

System.out.println("la lista è " + isOrdered ? "ORDINATA" : "NON ORDINATA")
```
