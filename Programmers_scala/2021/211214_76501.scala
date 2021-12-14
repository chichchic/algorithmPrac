object Solution {
    def solution(absolutes: Vector[Int], signs: Vector[Boolean]): Int = {
        var res = 0;
        for(i <- 0 until signs.length) {
            if(signs(i)) {
                res += absolutes(i);
            } else {
                res -= absolutes(i);
            }
        }
        res;
    }
}

object Solution {
    def solution(absolutes: Vector[Int], signs: Vector[Boolean]): Int = {
        absolutes.zip(signs).map({case (v, b) => if(b) v else -v}).reduce((a, b) => a + b)
    }
}