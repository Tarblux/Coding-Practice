const ONE_HOUR: u16 = 60 * 60;

fn maths() {
    let sum = 5 + 4;
    let subi = 9 - 2;
    let divs = 3 / 2;
    let mods = 4 % 3;

    println!("{}, {}, {}, {}", sum, subi, divs, mods);
}

fn cmpd_data(){

    let tupski:(i32,u16,f64) = (-345,250,3.14152);

    let first = tupski.0 ;
    let second = tupski.1;
    let third = tupski.2;

    println!("{},{},{}",first,second,third);
}

fn main() {
    let x = 5;
    println!("The value of x is: {}", x);
    {
        let x = 6;
        println!("The value of x is: {}", x);
    }
    println!("The value of x is: {} , {}", x, x);
    println!("One Hour is {} in seconds", ONE_HOUR);

    maths();
    cmpd_data();
}

