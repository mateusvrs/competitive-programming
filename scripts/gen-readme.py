import os
from pathlib import Path


def valid_section(section: Path) -> bool:
    return section.is_dir()


def get_section_name(section: str) -> str:
    return section.replace("-", " ").title()


def valid_file(file: Path) -> bool:
    return file.is_file() and file.name.endswith((".py", ".cpp"))


def get_algorithm_name(algorithm: str) -> str:
    name, lang = algorithm.split(".")
    name = name.replace("-", " ")
    name = name.replace("_", " ")
    if lang == "py":
        name += " (python)"
    return name


def get_relative_path(file: Path) -> str:
    return str(file).split("..")[1]


def get_algorithms_md() -> str:
    algorithmsPath = Path(__file__).parent / ".." / "algorithms"
    output = list()
    for section in os.listdir(algorithmsPath):
        if valid_section(algorithmsPath / section):
            current = {"name": get_section_name(section), "algorithms": list()}
            for algorithm in os.listdir(algorithmsPath / section):
                filePath = algorithmsPath / section / algorithm
                if valid_file(filePath):
                    current["algorithms"].append(
                        {
                            "name": get_algorithm_name(algorithm),
                            "path": get_relative_path(filePath),
                        }
                    )
            current["algorithms"] = sorted(
                current["algorithms"], key=lambda x: x["name"]
            )
            output.append(current)

    output = sorted(output, key=lambda x: x["name"])
    md = "## Algorithms\n\n"
    for section in output:
        md += f"- {section['name']}\n"
        for algorithm in section["algorithms"]:
            md += f"  - [{algorithm['name']}]({algorithm['path']})\n"

        md += "\n"

    return md


def get_intro() -> str:
    md = "# Competitive Programming\n\n"
    md += "In this repository, you'll find algorithms and data structure implementations for competitive programming, along with a [printable notebook](./notebook.pdf) with the implementations\n"
    md += "\n"
    return md


def get_references() -> str:
    md = """## References & Courses\n
- [TEP](https://github.com/edsomjr/TEP)
- [Competitive Programming Algorithms](https://github.com/iagorrr/Competitive-Programming-Algorithms)
- [UnBalloon](https://github.com/UnBalloon/programacao-competitiva)
- [Algorithms for Competitive Programming](https://cp-algorithms.com/)
- [Competitive Programing Book](https://cpbook.net/details?cp=4)
- [Competitive Programmer's Handbook](https://cses.fi/book/book.pdf)"""

    return md

def get_contributing() -> str:
    md = """## Contributing\n
If you want to contribute to this repository, you can do it by adding new algorithms or improving the existing ones. To do so, you can follow the steps below:

1. Fork this repository
2. Add or improve the algorithm you want
3. Create a pull request
4. Wait for the pull request to be reviewed and merged

**Obs:** You don't need to update the notebook, because it is generated automatically. Just add the algorithm to the `algorithms` folder and make sure that you have added it to the correct category folder such as `algorithms/math`, `algorithms/graphs`, etc.
"""
    md += "\n"

    return md

def get_steps() -> str:
    md = """## How to run locally?\n
If you want to create your own notebook, it is possible as follows:

Clone the project repository with the following command:

```bash
git clone https://github.com/mateusvrs/competitive-programming.git
```

To run the project, you need to install the global dependencies, which are:

- Docker Engine v24 (or higher)

From that, you can delete the algorithms inside the `algorithms` folder and add your own inside the same `algorithms` folder that are empty now. To customize the README.md, you can edit the `scripts/gen-readme.py` file. Finally, you can edit the university logo changing the `assets/logo.jpg` file (keeping the same name and extension).

Now, you can run the following command:

```bash
# Change the "Your Team Name" to the name of your own team
docker run -w /notebook -v .:/notebook mateusvrs/cp-notebook:v1.0 make team_name="Your Team Name"      
```
"""
    md += "\n"

    return md


def build_md() -> str:
    md = ""
    md += get_intro()
    md += get_algorithms_md()
    md += get_contributing()
    md += get_steps()
    md += get_references()
    return md


print(build_md())
