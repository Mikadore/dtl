import glob, subprocess, sys, os

if __name__ == "__main__":
    files = glob.glob(os.path.join(sys.path[0], '*.test'))
    for file in files:
        testname = "".join(file.split('.')[:-1])
        subprocess.run(["python3", testname + ".py"])        