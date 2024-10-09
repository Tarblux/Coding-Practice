fn main() {
    let s = String::from("hello");

    let slice = &s[0..2];
    let slice = &s[..2];

    let s = String::from("hello");

    let len = s.len();

    let slice = &s[3..len];
    let slice = &s[3..];

    let s = String::from("hello");

    let len = s.len();

    let slice = &s[0..len];
    let slice = &s[..];
}
