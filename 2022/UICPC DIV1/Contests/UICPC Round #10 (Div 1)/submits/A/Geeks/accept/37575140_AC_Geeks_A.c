import java.util.*

fun main() {
    val sc = Scanner(System.`in`)
    repeat(sc.nextInt()) {
        val n = sc.nextInt()
        val arr = hashMapOf<Int, Int>()
        repeat(n) {
            val b = sc.nextInt()
            val d = sc.nextInt()
            val bb = arr.getOrDefault(d, 0)
            if (b > bb)
                arr[d] = b
        }
        var isTen = 0
        var sum = 0
        for (key in arr.values) {
            sum += key
            isTen++
        }
        if (isTen == 10)
            println(sum)
        else
            println("MOREPROBLEMS")
    }
}