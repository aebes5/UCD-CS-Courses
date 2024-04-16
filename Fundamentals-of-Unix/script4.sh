file_name=$1 ; sort "$file_name" -o "$file_name"

#The result of the original command was clearing the file. It makes sense because the file can't be read and written into at the same time so it consequently clears. The execution is attempting to sort the file which is empty when the original file is lost in attempts to writing into the new/original file.
