import java.util.*

fun main() {
    val sc = Scanner(System.`in`)
    val t = sc.nextInt()
    repeat(t) {
        val bottles = sc.nextInt()
        val critics = sc.nextInt()
        var maxR = Int.MIN_VALUE
        var maxW = Int.MIN_VALUE
        repeat(critics) {
            val reds = sc.nextInt()
            val whites = sc.nextInt()
            maxR = maxOf(maxR, reds)
            maxW = maxOf(maxW, whites)
        }
        if (maxR + maxW > bottles)
            println("IMPOSSIBLE")
        else {
            repeat(maxR) { print("R")}
            repeat(maxW) { print("W")}
            repeat(bottles - maxR - maxW) { print("W")}
            println()
        }
    }
}