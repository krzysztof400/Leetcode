class Solution:
    def createGrid(self, m: int, n: int) -> list[str]:
        return [
            "."  * n if r == 0 else "#" * (n-1) + "."
            for r in range(m)
        ]