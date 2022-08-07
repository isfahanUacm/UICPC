import java.util.*

fun main() {
    val sc = Scanner(System.`in`)
    repeat(sc.nextInt()) {
        val w = sc.nextLong()
        val l = sc.nextLong()
        val minDim = minOf(w, l)
        val answers = LinkedList<Long>()
        answers.addLast(1L)
        var wRemind: Long
        var lRemind: Long
        for (i in 2..minDim) {
            wRemind = w % i
            lRemind = l % i
            if (
                wRemind == 0L && lRemind == 2L ||
                wRemind == 1L && lRemind == 1L ||
                wRemind == 2L && lRemind == 0L
            ) {
                answers.addLast(i)
            }
        }
        println("${answers.size} ${answers.joinToString(" ")}")
    }
}
