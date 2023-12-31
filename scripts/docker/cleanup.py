import os


def remove_docker_aux():
    """Remove the auxiliar files generated by docker runner"""
    to_remove = [
        "semicolon_delimited_script",
    ]
    for item in to_remove:
        if os.path.exists(item):
            os.remove(item)


if __name__ == "__main__":
    try:
        remove_docker_aux()
        print("Docker auxiliar files successfully removed!")
    except Exception as error:
        print("Error while removing Docker auxiliar files")
        print(error)
        exit(1)
