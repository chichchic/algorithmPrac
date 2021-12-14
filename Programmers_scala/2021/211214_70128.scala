object Solution {
    def solution(a: Vector[Int], b: Vector[Int]): Int = {
        a.zip(b).map({case (c, d) => c * d}).reduce((a, b) => a + b)
    }
}