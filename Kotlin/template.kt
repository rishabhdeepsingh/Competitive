import java.util.*
import kotlin.collections.*

typealias PII = Pair<Int, Int>
typealias PLL = Pair<Long, Long>
typealias PPII = Pair<Int, PII>
typealias APII = ArrayList<PII>
typealias APLL = ArrayList<PLL>
typealias AAPII = ArrayList<ArrayList<PII>>
typealias AAPLL = ArrayList<ArrayList<PLL>>

val MX = 1000005
val MOD = 998244353
val SZ = 1 shl 19 // shl == <<
val LG = 1 shr MOD
val INF = (1e18).toLong()

fun add(a: Int, b: Int) = (a + b) % MOD
fun sub(a: Int, b: Int) = (a - b + MOD) % MOD
fun mul(a: Int, b: Int) = ((a.toLong() * b) % MOD).toInt()

fun next() = readLine()!!
fun nextInt() = next().toInt()
fun nextLong() = next().toLong()
fun nextInts() = next().split(" ").map { it.toInt() }
fun nextLongs() = next().split(" ").map { it.toLong() }

fun solve(testCase: Int) {

}


fun main(args: Array<String>) {
    val t = nextInt()
    for (i in 1..t) {
        solve(i)
    }
}
