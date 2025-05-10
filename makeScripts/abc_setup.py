import os
import glob


TEMPLATE_DIR = os.path.join(os.path.dirname(__file__), '.', 'src')

TEMPLATE_NAME = 'script.{ext}'

def main():
    contest_id = input("コンテストのID (e.g., abc123 or 123): ").strip()
    contest_id = contest_id if contest_id[0:3] == "abc" else f"abc{int(contest_id)}"
    problems = input("問題のID (e.g., a b c): ").strip().split()
    language = input("作成するプログラミング言語 (e.g., cpp, py, rs): ").strip()
    
    ext_map = {
        "c": "c",
        "c++": "cpp",
        "cpp": "cpp",
        "py": "py",
        "rs": "rs",
    }
    
    ext = ext_map.get(language.lower())
    if not ext:
        print(f"Unsupported language: {language}")
        return
    

    tmpl_filename = TEMPLATE_NAME.format(ext=ext)
    tmpl_path = os.path.join(TEMPLATE_DIR, tmpl_filename)

    if os.path.isfile(tmpl_path):
        with open(tmpl_path, 'r') as f:
            boilerplate = f.read()
    else:
        boilerplate = ''
        print(f"Warning: template not found at {tmpl_path}. Creating empty file.")

    
    for prob in problems:
        base_dir = os.path.join(contest_id, prob.lower())
        os.makedirs(base_dir, exist_ok=True)
        
        pattern = os.path.join(base_dir, f"solution_*.{ext}")
        existing = glob.glob(pattern)
        nums = [int(os.path.splitext(os.path.basename(p))[0].split('_')[1]) for p in existing if p.split('_')[1].split('.')[0].isdigit()]
        next_num = max(nums, default=0) + 1

        filename = f"solution_{next_num}.{ext}"
        filepath = os.path.join(base_dir, filename)

        with open(filepath, 'w') as f:
            f.write(boilerplate)
        print(f"Created: {filepath}")

        
if __name__=="__main__":
    main()