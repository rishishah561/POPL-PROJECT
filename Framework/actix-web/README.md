#PoPL Aspect of Actix-Web

##References and Borrowing (Line 13): The function async fn echo(req_body: String) takes ownership of the req_body parameter, illustrating the concept of ownership. This function could be modified to use references (&str) for borrowing instead, promoting a more flexible ownership model.

##Trait Objects (Line 7): The use of [get("/")] to define the route handler async fn hello() -> impl Responder showcases the concept of trait objects, allowing for dynamic dispatch of different types implementing the Responder trait.

##Mutability and Immutability (Line 13): The absence of mut in req_body: String indicates immutability by default, preventing accidental~modifications to the original data and aligning with Rust's ownership model
