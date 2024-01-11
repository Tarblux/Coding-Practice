//this is my first javascript code 
console.log("Hello Squirrel");

let fname = 'Whipski';

console.log(fname);

//Constants

const interestRate = 0.3;
// interestRate = 9 , This will throw an error since we can't reassign a constant.
console.log(interestRate)

//Primitives

let age = 30 ; // Number Literal
let name2 = 'Tariq' ; //String Literal
let isApproved = false ; // Boolean Literal 
let firstName; // If we don't initialize it by default it will be undefined 
let lastName = null ; // This clears  the value stored in a variable 

//functions 

function greet(name , lastName) {
        console.log('Hello ' + name + lastName )
}

greet('John' , 'Smith')

function add(a,b) {

    sum = a + b 
    return sum

}

// Notice that this prints undefined , that's becuase we didn't pass a second argument to the function so the last name parameter in the function ended up
// being undefined

greet('Mary')

// Function that calculates a value 

function square(number) {
   return number * number ;     
}

// Look into the structure of this more  

function factorial(number) {
        
        if (number === 0) {
                return 1;
        }
        return number * factorial(number - 1);
}

console.log(square(9))
