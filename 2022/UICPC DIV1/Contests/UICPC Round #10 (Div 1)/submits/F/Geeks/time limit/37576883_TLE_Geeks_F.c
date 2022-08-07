import java.util.*

fun main() {
    val sc = Scanner(System.`in`)
    repeat(sc.nextInt()) {
        val w = sc.nextLong()
        val l = sc.nextLong()
        val minDim = minOf(w, l)
        val answers = StringBuilder(" 1")
        var size = 1
        for (i in 2..minDim) {
            if (
                w % i == 0L && (l - 2) % i == 0L ||
                w % i == 1L && (l - 1) % i == 0L ||
                w % i == 2L && l % i == 0L
            ) {
                answers.append(" $i")
                size++
            }
        }
        println("$size$answers")
    }
}