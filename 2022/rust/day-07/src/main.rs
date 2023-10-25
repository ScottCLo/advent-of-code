use std::fs::read_to_string;

struct File{
    name: String,
    size: u32,
}

struct Folder{
    name: String,
    size: u32,
    items: Vec<Item>,
}

enum Item {
    File(File),
    Folder(Folder),
}


fn main() {
    let input = read_to_string("example.txt").unwrap();
    input.split("$").map(|x| x.lines());
}
