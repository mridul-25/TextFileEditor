int cFileExists(const char * filename)
{
    /* try to open file to read */
    FILE *file_check;
    if (file_check = fopen(filename, "r")){
        fclose(file_check);
        return 1;
    }
    return 0;
}
// Checks if the file exists or not
//if file exists it will return 1 
//if file doesn't exist it will return 0
