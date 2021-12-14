object Solution {
    def solution(numbers: Vector[Int]): Int = {
        0.to(9).filter((v => !numbers.contains(v))).reduce((a, b) => a + b)
    }
}