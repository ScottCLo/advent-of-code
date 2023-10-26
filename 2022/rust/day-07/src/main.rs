use std::{fs::read_to_string, iter, option};

struct File{
    name: String,
    size: u32,
}

struct Folder{
    name: String,
    size: u32,
    items: Vec<Item>,
}

impl Folder {
    fn new(name: String) -> Folder{
        Folder {name: name, size: 0, items: Vec::new()}
    }

    fn add_item(&mut self, item: Item){
        self.size += item.get_size();
        self.items.push(item);
    }

    fn get_items(&self) -> std::slice::Iter<'_, Item> {
       self.items.iter()
    }

    fn print_tree(&self, i:usize){
        let mut indent = String::from("");
        for _ in 0..i {
            indent.push_str("    ");
        }
        println!("{}{} - {}",indent, self.name, self.size);
        for x in &self.items {
            if x.is_file() {
                println!("{}    {}", indent, x.to_string());
            }
            if x.is_folder() {
                x.get_folder().unwrap().print_tree(i+1);
            }
        }
    }
    fn to_iter(&self) -> Vec<&Item>{
        let mut items: Vec<&Item> = Vec::new();
        for x in &self.items{
            if x.is_file() {
                items.push(&x);
            }else {
                items.append(&mut x.get_folder().unwrap().to_iter())
            }
        }
        items
    }

    fn all_folders(&self) -> Vec<&Item>{
        let mut items: Vec<&Item> = Vec::new();
        for x in &self.items{
            if x.is_folder() {
                items.push(&x);
                items.append(&mut &mut x.get_folder().unwrap().all_folders())
            }
        }
        items
    }

    fn contrains_folder(&self, f:&str) -> bool{
        for x in &self.items {
            if x.get_name() == &f.to_string() && x.is_folder(){
                return true;
            }
        }
        false
    }

    fn get_folder(&self, f:&str) -> Option<&Folder>{
        for x in &self.items {
            if x.get_name() == &f.to_string() && x.is_folder() {
                return x.get_folder();
            }
        }
        None
    }

    fn get_mut_folder(&mut self, f:&str) -> Option<&mut Folder>{
        for x in &mut self.items {
            if x.get_name() == &f.to_string() && x.is_folder() {
                return x.get_mut_folder();
            }
        }
        None
    }
}

enum Item {
    File(File),
    Folder(Folder),
}

impl Item {
    fn to_string(&self) -> String {
        match self {
            Item::File(x) => format!("{} - {}", x.name, x.size),
            Item::Folder(x) => format!("{} - {}", x.name, x.size),
        }
    }

    fn get_size(&self) -> u32{
        match self {
            Item::File(x) => x.size,
            Item::Folder(x) => x.size,
        }
    }

    fn get_name(&self) -> &String{
        match self {
            Item::File(x) => &x.name,
            Item::Folder(x) => &x.name,
        }
    }

    fn is_file(&self) -> bool {
        match self {
            Item::File(_) => true,
            _ => false,
        }
    }

    fn is_folder(&self) -> bool {
        match self {
            Item::Folder(_) => true,
            _ => false,
        }
    }

    fn get_file(&self) -> Option<&File> {
        match self {
            Item::File(x) => Some(x),
            _ => None,
        }
    }

    fn get_folder(&self) -> Option<&Folder> {
        match self {
            Item::Folder(x) => Some(x),
            _ => None,
        }
    }

    fn get_mut_folder(&mut self) -> Option<&mut Folder> {
        match self {
            Item::Folder(x) => Some(x),
            _ => None,
        }
    }
}


/*fn test(){
    let input = read_to_string("example.txt").unwrap();
    let input: Vec<(Option<&str>, Option<Vec<&str>>)> = input.split("$").map(|x| {
        let mut lines = x.lines();
        let c = lines.next();
        let r = lines.collect::<Vec<&str>>();
    });
}*/

fn test() {
    let mut drive = Folder::new(String::from("drive"));
    let mut target = &mut drive;
    let mut history: Vec<&mut Folder> = Vec::new();
    let input = read_to_string("example.txt").unwrap();
    let cmds: Vec<(Option<&str>, Vec<&str>)> = input.split("$").map(|x|{
        let mut lines = x.lines();
        let c = lines.next();
        let r = lines.collect::<Vec<&str>>();
        (c, r)
    }).filter(|x| x.0.is_some()).collect();

    for x in cmds {
        let mut cmd = x.0.unwrap().trim().split_whitespace();
        match cmd.next().unwrap() {
            "cd" => {
                let f = cmd.next().unwrap();
                match f{
                    ".." => target = history.pop().unwrap(),
                    _ => {
                        if target.contrains_folder(f){
                            //history.push(*target);
                            //target = history.last().unwrap().get_mut_folder(f).unwrap();
                        }
                    }
                }
            },
            "ls" => {
                print!("HROKOG");
                /*for r in x.1{
                    let mut i = r.split_whitespace();
                    /match i.next().unwrap(){
                        "dir" => target.add_item(Item::Folder(Folder::new(i.next().unwrap().to_string()))),
                        _ => print!("help"),//&target.add_item(Item::File(File { name: i.next().unwrap().to_string(), size:0 })),
                    };
                }*/
            },
            _ => panic!("Bad command!"),
        }
    }

}

fn main(){
    let mut x = 1;
    let mut y = 2;
    let mut a = &mut x;
    println!("a={a}");
    a = &mut y;
    println!("a={a}");
    *a = 3;
    println!("a={a}");
    a = &mut x;
    println!("a={a}");
    a = &mut y;
    println!("a={a}");

}