use std::{fs, io};

#[derive(Debug)]
pub struct AppIO {
  folderpath: String,
  filenames: Vec<String>,
}

impl AppIO {
  pub fn new(foldername: String) -> io::Result<AppIO> {
    let folderpath = fs::canonicalize(foldername)?.to_string_lossy().to_string();

    let filenames: Vec<String> = match fs::read_dir(&folderpath) {
      Ok(entries) => {
        entries
          .filter_map(Result::ok)
          .filter_map(| entry | entry.file_name().to_str().map(ToString::to_string))
          .collect()
      },
      Err(err) => {
        eprintln!("Err: {}", err);

        Vec::new()
      }
    };

    Ok(AppIO{folderpath, filenames})
  }
}