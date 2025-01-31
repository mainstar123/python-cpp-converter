# Python to C++ Converter

This project converts Python code to high-performance C++ code using AI models like GPT and Claude. The generated C++ code aims to produce identical output to the original Python code in the fastest possible time.

## Setup

1. **Clone the repository:**

   ```sh
   git clone <repository-url>
   cd python-cpp-converter
   ```

2. **Install dependencies:**

   ```sh
   pip install -r requirements.txt
   ```

3. **Set up environment variables:**
   Create a `.env` file in the project root and add your API keys:
   ```env
   OPENAI_API_KEY=your-openai-api-key
   ANTHROPIC_API_KEY=your-anthropic-api-key
   ```

## Usage

1. **Run the application:**

   ```sh
   python main.py
   ```

2. **Convert Python code to C++:**

   - Enter your Python code in the provided textbox.
   - Select the AI model (GPT or Claude).
   - Click the "Convert code" button to generate the C++ code.

3. **Execute the code:**
   - Click "Run Python" to execute the Python code and see the output.
   - Click "Run C++" to compile and execute the generated C++ code and see the output.

## Notes

- The project uses `gradio` for the user interface.
- Ensure you have `clang++` installed for compiling the C++ code.

## License

This project is licensed under the MIT License.
