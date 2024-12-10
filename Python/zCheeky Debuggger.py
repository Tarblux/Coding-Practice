import matplotlib.pyplot as plt

def plot_histogram(heights, current_rect=None):
    plt.bar(range(len(heights)), heights, color='skyblue')
    if current_rect:
        x, width, height = current_rect
        plt.bar(x, height, width=width, color='salmon', alpha=0.5)
    plt.xlabel('Index')
    plt.ylabel('Height')
    plt.title('Histogram of Heights with Current Rectangle')
    plt.show()

def largestRectangleArea(heights):
    stack = []  # Stack to store indices
    max_area = 0  # Variable to store the maximum area
    n = len(heights)
    
    for i in range(n):
        # Ensure the heights in the stack are in non-decreasing order
        while stack and heights[i] < heights[stack[-1]]:
            h = heights[stack.pop()]
            start_index = stack[-1] + 1 if stack else 0
            w = i if not stack else i - stack[-1] - 1
            max_area = max(max_area, h * w)
            print(f"Popped height: {h}, width: {w}, start index: {start_index}, end index: {i - 1}, max_area: {max_area}")
            plot_histogram(heights, (start_index, w, h))
        stack.append(i)
    
    # Calculate the area for the remaining bars in the stack
    while stack:
        h = heights[stack.pop()]
        start_index = stack[-1] + 1 if stack else 0
        w = n if not stack else n - stack[-1] - 1
        max_area = max(max_area, h * w)
        print(f"Remaining height: {h}, width: {w}, start index: {start_index}, end index: {n - 1}, max_area: {max_area}")
        plot_histogram(heights, (start_index, w, h))
    
    return max_area

# Example usage
heights = [2, 8, 5, 6, 2, 3]
print(f"Largest Rectangle Area: {largestRectangleArea(heights)}")  # Output: 10