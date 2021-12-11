object Solution {

    def solution(a: Long, b: Long): Long = {
        val s = if(a < b) a else b;
        val e = if(a < b) b else a;
        (s to e).sum
    }
}