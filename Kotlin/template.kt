
import java.util.*
 
val MX = 1000005
val MOD = 998244353
val SZ = 1 shl 19 // shl == <<
val INF = (1e18).toLong()
 
fun add(a: Int, b: Int) = (a + b) % MOD
fun sub(a: Int, b: Int) = (a - b + MOD) % MOD
fun mul(a: Int, b: Int) = ((a.toLong() * b) % MOD).toInt()
 
fun next() = readLine()!!
fun nextInt() = next().toInt()
fun nextLong() = next().toLong()
fun nextInts() = next().split(" ").map { it.toInt() }
fun nextLongs() = next().split(" ").map { it.toLong() }

fun solve(){
  
}


fun main(args: Array<String>) {
    val t = nextInt()
    for (i in 0..t-1) {
        solve()
    }
}
