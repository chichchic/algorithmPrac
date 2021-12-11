object Solution {
    def solution(lottos: Vector[Int], win_nums: Vector[Int]): Vector[Int] = {
        val min_count = lottos.filter(x => win_nums.exists(y => x == y)).size;
        val max_count = lottos.filter(x => x == 0).size + min_count;
        val ranking = List(6, 6, 5, 4, 3, 2, 1);
        return Vector[Int](ranking(max_count), ranking(min_count))
    }
}