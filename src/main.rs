mod util;

use clap::Parser;

#[derive(Parser, Debug)]
#[command(author = "J0sueTM <teodoro.josue@protonmail.ch>", version = "1.0", about = "", long_about = None)]
struct Args {
    // Path of the gate project to run
    #[clap(short, long, conflicts_with_all=&["compile", "output"])]
    run: Option<String>,

    // Path of the gate project to compile
    #[clap(short, long, conflicts_with="run", requires="output")]
    compile: Option<String>,

    // Desired filename binary output
    #[clap(short, long, requires="compile")]
    output: Option<String>
}

fn main() {
    let args = Args::parse();

    let foldername = args.run
        .or(args.compile)
        .expect("Either `run` or `compile` argument must be provided");

    let app_io_info = util::fs::AppIO::new(foldername);

    println!("{:#?}", app_io_info);
}