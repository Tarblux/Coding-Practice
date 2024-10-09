// fn main() {
//     let number = 3;

//     if number < 0 {
//         println!("condition was true");} 
//     else {
//         println!("condition was false");}

//     let condition = true;
//     let number = if condition { 5 } else { 6 };
    
//     println!("The value of number is: {number}");
// }

fn main() {
    let mut counter = 0;

    let result = loop {
        counter += 1;

        if counter == 10 {
            break counter * 2;
        }
    };

    println!("The result is {result}");
}
