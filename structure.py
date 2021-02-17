import os
import re

for entry in os.scandir(os.getcwd()):
    filename = os.path.splitext(entry.name)[0]
    if entry.is_file() and re.match("\\d", filename):
        directory = os.path.join(os.getcwd(), filename)

        if not os.path.exists(directory):
            print(f"Create {directory}")
            os.makedirs(directory)

        to = os.path.join(directory, entry.name)
        print(f"Move {entry.name} from {entry.path} to {to}")
        os.replace(entry.path, to)
