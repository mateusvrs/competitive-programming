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
    md = "## Algorithms\n"
    for section in output:
        md += f"- {section['name']}\n"
        for algorithm in section["algorithms"]:
            md += f"    - [{algorithm['name']}]({algorithm['path']})\n"

        md += "\n"

    md += "\n"
    return md


def get_intro() -> str:
    md = "# Competitive Programming\n"
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
- [Competitive Programmer's Handbook](https://cses.fi/book/book.pdf)
    """
    md += "\n"

    return md


def build_md() -> str:
    md = ""
    md += get_intro()
    md += get_algorithms_md()
    md += get_references()
    return md


print(build_md())
