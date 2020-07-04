import sys
import subprocess

subprocess.run(["cmake"] + sys.argv + ["-DCMAKE_PREFIX_PATH={}".format(';'.join(sys.path))])
