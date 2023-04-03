use std::{fs, io, path};
use log;

#[derive(Debug)]
pub struct AppIO {
  folderpath: &'static path::Path,
  filenames: Vec<String>,
}

impl AppIO {
    pub fn new(foldername: String) -> io::Result<AppIO> {
        let path_binding = fs::canonicalize(foldername)?;
        let folderpath = path_binding.as_path();

        let filenames = Self::get_app_files(folderpath);

        Ok(AppIO{folderpath, filenames})
    }

    fn get_app_files(folderpath: &path::Path) -> Vec<String> {
        if !folderpath.is_dir() {
            log::error!("Given folderpath isn't an app dir");

            return Vec::new();
        }

        let filenames: Vec<String> = fs::read_dir(folderpath)
            .map(| entries | {
                entries
                    .filter_map(Result::ok)
                    .flat_map(| entry | {
                        let pathbuf = entry.path();
                        if pathbuf.is_dir() {
                            Self::get_app_files(pathbuf.as_path())
                        } else {
                            let path = pathbuf.as_path().canonicalize().unwrap();
                            let full_path = path.to_string_lossy().to_string();

                            vec![full_path]
                        }
                    })
                    .filter(| filename | filename.ends_with(".gate"))
                    .collect()
            })
            .unwrap_or_else(| err | {
                log::error!("{}", err);

                Vec::new()
            });

        filenames
    }
}