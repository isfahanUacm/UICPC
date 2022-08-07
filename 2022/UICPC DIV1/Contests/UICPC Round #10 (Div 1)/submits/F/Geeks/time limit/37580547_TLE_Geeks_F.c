import java.util.*
import kotlin.math.ceil

fun main() {
    val sc = Scanner(System.`in`)
    repeat(sc.nextInt()) {
        val w = sc.nextLong()
        val l = sc.nextLong()
        val minDim = minOf(w, l)
        val answers = LinkedList<Long>()
        answers.addLast(1L)
        var wRemind: Long
        for (i in 2..ceil(minDim / 2.0).toLong() + 1) {
            wRemind = w % i
            if (
                wRemind == 0L && (l - 2) % i == 0L ||
                wRemind == 1L && (l - 1) % i == 0L ||
                wRemind == 2L && l % i == 0L
            ) {
                answers.addLast(i)
            }
        }
        if (l == w)
            answers.add(w - 1)
        println("${answers.size} ${answers.joinToString(" ")}")
    }
}