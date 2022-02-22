import subprocess
from multiprocessing import Pool
from json import dump

def generate_data(dislocations):
    process = subprocess.run(["../simulation/program"], input=str(dislocations).encode('utf8'), capture_output = True)
    raw_output = process.stdout.decode('utf8')
    data = list(map(int, raw_output.split('\n')[:-1:]))
    return data

width = 20
height = 20

with Pool(8) as p:
    data = p.map(generate_data, range(width * height + 1));


    
with open('data.json', 'w') as f:
    dump(data, f)
