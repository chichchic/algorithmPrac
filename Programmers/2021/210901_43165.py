def solution(numbers, target):
    answer = 0

    def dfs(current, index):
        nonlocal answer
        if index == len(numbers):
            if current == target:
                answer += 1
            return
        dfs(current + numbers[index], index + 1)
        dfs(current - numbers[index], index + 1)
    dfs(0, 0)

    return answer
