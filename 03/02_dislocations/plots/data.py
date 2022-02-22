import subprocess
from multiprocessing import Pool
from json import dump

def generate_data(dislocations):
    process = subprocess.run(["../simulation/program"], input=str(dislocations).encode('utf8'), capture_output = True)
    raw_output = process.stdout.decode('utf8')
    data = list(map(int, raw_output.split('\n')[:-1:]))
    print("Generated data for #{} dislocations".format(dislocations))
    return data

width = 40
height = 40

with Pool(8) as p:
    data = p.map(generate_data, range(width * height + 1), chunksize=10);


    
with open('data.json', 'w') as f:
    dump(data, f)
