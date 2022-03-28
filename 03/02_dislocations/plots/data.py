import subprocess
from multiprocessing import Pool
from json import dump

def generate_data_1(dimentions):
    width, height = dimentions
    process = subprocess.run(["../one_dislocation"], input="{} {}".format(width, height).encode('utf8'), capture_output = True)
    raw_output = process.stdout.decode('utf8')
    data = list(map(int, raw_output.split('\n')[:-1:]))
    print("Generated data for width: {}, height: {}".format(width, height))

    return data

def generate_data_2(dislocations):
    process = subprocess.run(["../simulation/program"], input=str(dislocations).encode('utf8'), capture_output = True)
    raw_output = process.stdout.decode('utf8')
    data = list(map(int, raw_output.split('\n')[:-1:]))
    print("Generated data for #{} dislocations".format(dislocations))
    return data

def generate_data_3(width):
    process = subprocess.run(["../one_line_dislocation"], input=str(width).encode('utf8'), capture_output=True)
    raw_output = process.stdout.decode('utf8')
    data = list(map(int, raw_output.split('\n')[:-1:]))
    print("Generated data for width: {}".format(width))
    return data

def generate_data_4(area):
    process = subprocess.run(["../line-crystal/program"], input=str(area).encode('utf8'), capture_output = True)
    raw_output = process.stdout.decode('utf8')
    data = list(map(int, raw_output.split('\n')[:-1:]))
    print("Generated data for #{} dislocations".format(area))
    return data

    
width = 40
height = 40

line_width = 200

with Pool(8) as p:
    data = {
        'lab 3': {
            'one dislocation': p.map(generate_data_3, range(1, line_width + 1), chunksize=10),
            'area': p.map(generate_data_4, range(line_width), chunksize=10)
        },
        'lab 1': p.map(generate_data_1, [(width, height) for width in range(1, 40) for height in range(1, 40)], chunksize=10),
        'lab 2': p.map(generate_data_2, range(width * height + 1), chunksize=10),
        
    }


    
with open('data.json', 'w') as f:
    dump(data, f)
