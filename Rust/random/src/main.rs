fn main() {
    
    let nums : [i32;5] = [1,2,3,4,5];

    let first_element = nums[0];

    println!("{}",first_element);

    for element in nums.iter() {
        println!("{}", element);
    }
}
