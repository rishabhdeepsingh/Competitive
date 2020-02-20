# KOTLIN

- [Left Shift](#left-shift)
- [Right Shift](#right-shift)
- [Unsigned Shift](#unsigned-shift)
- [Type Alias](#type-alias)
- [2D Array](#2d-arrays)
- [Comparing Pairs](#comparing-pairs)
- [Hash Map](#hashmap)
- [If Else](#if-else)
- [Imports](#imports)
- [Printing](#printing)
- [Ranges](#ranges)
- [Sorting](#sorting)
- [Swappign](#swap-int)
- [Type Alias](#type-alias)
- [Sources](#sources)

# Examples

### Left Shift
```kotlin
val a = 212     // (212  : 11010100
val b = a shl 1 // (424  : 110101000)
val c = a shl 0 // (212  : 11010100)
val d = a shl 4 // (3392 : 110101000000)
```
### Right Shift
```kotlin
val a = 212     // (212 : 11010100
val b = a shr 1 // (106 : 01101010)
val c = a shr 0 // (212 : 11010100)
val d = a shr 8 // (000 : 00000000)
```
### Unsigned Shift
```kotlin
val a = 5
val x = a ushr 1 // 2
val b = -5
val y = b ushr 1 // 2147483645
val z = b shr 1  // -3
```
### Type Alias
```kotlin
arrayList.add(PPII(1, PII(1, 2)))
```

# Samples

### 2D Arrays
```kotlin
val type1 = Array(n) { IntArray(n) }
val type2 = Array(n, { IntArray(m) })
val type3 = arrayOf(
    intArrayOf(8, 9, 1, 13),
    intArrayOf(3, 12, 7, 5),
    intArrayOf(0, 2, 4, 11),
    intArrayOf(6, 10, 15, 14)
)
```

### Comparing Pairs
```kotlin
class CustomComparator : Comparator<Pair<Int, Pair<Int, Int>>> {
    override fun compare(o1: Pair<Int, Pair<Int, Int>>, o2: Pair<Int, Pair<Int, Int>>): Int {
        return o1.first.compareTo(o2.first)
    }
}

val arrayList = ArrayList<Pair<Int, Pair<Int, Int>>>()
val sorted = arrayList.sortedWith(CustomComparator())
val sorted2 = arrayList.sortedWith(compareBy({ -it.second }, { it.first }))
```
### HashMap
```kotlin
val hashMap = HashMap<String, Int>()
for (i in 0..n - 2) {
    val w = s.substring(i, i + 2)
    val c = hashMap.getOrElse(w) { 0 }
    hashMap.put(w, c + 1)
}
```

### if else
```kotlin
val max = if (a > b) a else b
```

### Imports 
```kotlin
import kotlin.arrayOf as Arr
import kotlin.intArrayOf as Iarr
```

### Printing
```kotlin
println("${l+1} and $r")
```

### Ranges
```kotlin
// [ or ] => Inclusive | ( or ) => Exclusive
for (i in 1..n) print(i) // [1, n]
for (i in 1 until n) print(i) // [1, n)
for (i in n  downTo 1) print(i) // [n, 1]
for (i in 1..n step 2) print(i) // 1, 3, 5 , 7, 9 ...
for (i in 8 downTo 1 step 2) print(i) // 8, 6, 4, 2
```

### Sorting
```kotlin
val b = nextLongs().sorted() // a is mutable list
val a = arrayListOf<Long>()
a.addAll(nextLongs())
a.sort()
```

### Swap Int
```kotlin
var a = 10
var b = 30
a = b.also { b = a }
```

### Type Alias
```kotlin
typealias PII = Pair<Int, Int>
typealias PPII = Pair<Int, PII>
```

# Sources
- [Array](https://kotlinlang.org/api/latest/jvm/stdlib/kotlin/-array/index.html)
- [ArrayList](https://kotlinlang.org/api/latest/jvm/stdlib/kotlin.collections/-array-list/index.html)
- [Binary Search](https://kotlinlang.org/api/latest/jvm/stdlib/kotlin.collections/binary-search.html)
- [Ranges](https://kotlinlang.org/docs/reference/ranges.html)
