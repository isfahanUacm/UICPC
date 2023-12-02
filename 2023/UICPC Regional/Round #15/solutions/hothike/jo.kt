import java.util.*
import kotlin.math.max

fun main() {
    val scan = Scanner(System.`in`)
    val n = scan.nextInt()
    val T = (0 until n).map{scan.nextInt()}
    var i0 = 0
    var min = Integer.MAX_VALUE
    for (i in 0..(n-3)) {
        val m = max(T[i], T[i+2])
        if (m < min) {
            i0 = i
            min = m
        }
    }
    println("${i0+1} $min")
}
